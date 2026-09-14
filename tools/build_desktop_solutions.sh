#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

single=(
  00-course-setup
  01-function-gain
  02-array-buffer
  03-reference-in-place
  04-pointer-buffer
  05-class-gain
  06-stateful-distortion
  07-const-enum-modes
  09-sample-rate
  10-db-gain
  11-waveshaping
  12-tone-filter
  13-delay-circular-buffer
)

for lesson in "${single[@]}"; do
  dir="$ROOT/lessons/$lesson/solution"
  echo "[build] $lesson"
  g++ -std=c++20 -Wall -Wextra -Wpedantic "$dir/main.cpp" -o /tmp/course-app
  (cd /tmp && /tmp/course-app >/dev/null)
done

echo "[build] 08-project-structure"
make -C "$ROOT/lessons/08-project-structure/solution" clean app >/dev/null
"$ROOT/lessons/08-project-structure/solution/app" >/dev/null
make -C "$ROOT/lessons/08-project-structure/solution" clean >/dev/null

echo "[build] 14-mini-pedal-engine"
make -C "$ROOT/lessons/14-mini-pedal-engine/solution" clean app >/dev/null
"$ROOT/lessons/14-mini-pedal-engine/solution/app" >/dev/null
make -C "$ROOT/lessons/14-mini-pedal-engine/solution" test >/dev/null
make -C "$ROOT/lessons/14-mini-pedal-engine/solution" clean >/dev/null

echo "All desktop solutions built successfully."
