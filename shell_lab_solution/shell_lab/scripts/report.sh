#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
LAB_DIR="$(dirname "$SCRIPT_DIR")"
REPORT_FILE="$LAB_DIR/notes/report_$(date +%Y-%m-%d).md"
DATA_DIR="$LAB_DIR/data"

FILE_COUNT=$(ls "$DATA_DIR" | wc -l)

cat > "$REPORT_FILE" << REPORT
# Session Report - $(date +%Y-%m-%d)

- **Current User:** $(whoami)
- **Current Path:** $(pwd)
- **Files in data/:** $FILE_COUNT
REPORT

echo "Report created: $REPORT_FILE"
