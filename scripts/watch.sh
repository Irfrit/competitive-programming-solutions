#!/usr/bin/env bash
# Real-time watcher: automatically updates README.md whenever any .cpp file is added, removed, or moved.
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$DIR"

echo "Watching solution folders for changes..."
WATCH_DIRS=(atcoder CodeForces CSES USACO AlgorithmRoadmap)
EXISTING_DIRS=()
for d in "${WATCH_DIRS[@]}"; do
    [ -d "$d" ] && EXISTING_DIRS+=("$d")
done

inotifywait -m -r -e create,delete,moved_to,moved_from "${EXISTING_DIRS[@]}" 2>/dev/null | \
while read -r directory event file; do
    if [[ "$file" == *.cpp ]]; then
        echo "[$(date +'%H:%M:%S')] Change detected ($event: $file in $directory). Updating README..."
        python3 "$DIR/scripts/update_readme.py"
    fi
done
