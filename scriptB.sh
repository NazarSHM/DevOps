#!/bin/bash

# scriptB.sh — генератор навантаження
# Відправляє GET-запити до сервера кожні 5–10 сек, асинхронно

while true; do
  x=$(awk -v min=0.1 -v max=2 'BEGIN{srand(); print min+rand()*(max-min)}')
  terms=$((RANDOM % 10 + 5))
  echo "[Запит] x=$x, terms=$terms"
  curl -s "http://localhost/?x=$x&terms=$terms" &
  sleep $((RANDOM % 6 + 5))
done
