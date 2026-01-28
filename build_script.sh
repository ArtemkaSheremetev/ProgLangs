#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
ASM="$SCRIPT_DIR/build/program.s"
LOGIN=${LOGIN:-"506858"}
PASSWORD=${PASSWORD:-"f082be5e-6c2e-4476-90e8-4035526d9d9d"}

MANAGER=(mono "$SCRIPT_DIR/architecture/Portable.RemoteTasks.Manager.exe")

echo "Assembling..."

ASSEMBLE_OUTPUT="$(
  "${MANAGER[@]}" \
    -ul "$LOGIN" \
    -up "$PASSWORD" \
    -s AssembleDebug \
    definitionFile "$SCRIPT_DIR/architecture/reg32.target.pdsl" \
    archName "harvard32" \
    asmListing "$ASM" \
    sourcesDir "$SCRIPT_DIR/build" \
  2>&1 | tee assemble_remote.log
)"

GUID="$(echo "$ASSEMBLE_OUTPUT" | grep -oE '[0-9a-fA-F]{8}-([0-9a-fA-F]{4}-){3}[0-9a-fA-F]{12}' | head -n1)"
if [[ -z "${GUID:-}" ]]; then
  echo "GUID not found. See assemble_remote.log"
  exit 1
fi
echo "GUID: $GUID"

echo "Downloading out.ptptb (retry)..."

# Несколько попыток: либо задача ещё не закончилась, либо файл появляется с задержкой
ok=0
for i in $(seq 1 20); do
  if "${MANAGER[@]}" -ul "$LOGIN" -up "$PASSWORD" -g "$GUID" -r "out.ptptb" -o "out_prog.ptptb" 2>&1 | tee -a download_remote.log; then
    ok=1
    break
  fi
  sleep 1
done

if [[ $ok -ne 1 ]]; then
  echo "Failed to download out.ptptb after retries."
  echo "Check assemble_remote.log and download_remote.log"
  exit 1
fi

echo "OK: out_prog.ptptb downloaded"