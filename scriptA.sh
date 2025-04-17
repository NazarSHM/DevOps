#!/bin/bash

# Контейнери, порти та ядра
containers=("srv1" "srv2" "srv3")
ports=(8001 8002 8003)
cpus=("0" "1" "2")
image="nazarshm/http_server:latest"


# Запуск контейнера
start_container() {
  name=$1
  port=$2
  cpu=$3
  sudo docker run -d --name $name --cpuset-cpus=$cpu -p $port:80 $image
  echo "$name запущено на CPU $cpu, порт $port"
}

# Зупинка контейнера
stop_container() {
  name=$1
  sudo docker stop $name && sudo docker rm $name
  echo "$name зупинено"
}

# Чи контейнер перевантажений (>20%)
check_busy() {
  name=$1
  cpu_usage=$(sudo docker stats --no-stream --format "{{.CPUPerc}}" $name | tr -d '%')
  awk "BEGIN {exit !($cpu_usage > 20)}"
}

# Початковий запуск srv1
if ! sudo docker ps | grep -q srv1; then
  start_container "srv1" 8001 0
fi

# Основний цикл
while true; do
  # Розширення
  if sudo docker ps | grep -q srv1 && check_busy srv1; then
    echo "srv1 перевантажений, чекаємо 2 хвилини..."
    sleep 120
    sudo docker ps | grep -q srv2 || start_container "srv2" 8002 1
  fi

  if sudo docker ps | grep -q srv2 && check_busy srv2; then
    echo "srv2 перевантажений, чекаємо 2 хвилини..."
    sleep 120
    sudo docker ps | grep -q srv3 || start_container "srv3" 8003 2
  fi

  # Згортання
  for i in 2 1; do
    name=${containers[$i]}
    if sudo docker ps | grep -q $name; then
      cpu_usage=$(sudo docker stats --no-stream --format "{{.CPUPerc}}" $name | tr -d '%')
      if (( $(echo "$cpu_usage < 1.0" | bc -l) )); then
        echo "$name idle... чекаємо 2 хвилини..."
        sleep 120
        cpu_usage=$(sudo docker stats --no-stream --format "{{.CPUPerc}}" $name | tr -d '%')
        if (( $(echo "$cpu_usage < 1.0" | bc -l) )); then
          stop_container $name
        fi
      fi
    fi
  done

  # Оновлення образів
  echo "Перевірка оновлень для $image..."
  sudo docker pull $image
  if [ $? -eq 0 ]; then
    echo "Оновлення запущених контейнерів..."
    for i in 0 1 2; do
      name=${containers[$i]}
      port=${ports[$i]}
      cpu=${cpus[$i]}
      if sudo docker ps | grep -q $name; then
        echo "Оновлюємо $name..."
        stop_container $name
        start_container $name $port $cpu
        sleep 3
      fi
    done
  fi

  sleep 60
done
