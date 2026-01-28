#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

EXE="${EXE:-"$SCRIPT_DIR/out_prog.ptptb"}"
LOGIN=${LOGIN:-"506858"}
PASSWORD=${PASSWORD:-"f082be5e-6c2e-4476-90e8-4035526d9d9d"}
ARC="${ARC:-harvard32}"

ARC_FILE="${ARC_FILE:-"$SCRIPT_DIR/architecture/reg32.target.pdsl"}"

MANAGER=(mono "$SCRIPT_DIR/architecture/Portable.RemoteTasks.Manager.exe")

echo "Executing..."

# быстрые проверки, чтобы сразу увидеть проблему путей
[[ -f "$EXE" ]] || { echo "Error: binary not found: $EXE" >&2; exit 1; }
[[ -f "$ARC_FILE" ]] || { echo "Error: definitionFile not found: $ARC_FILE" >&2; exit 1; }

"${MANAGER[@]}" \
  -ul "$LOGIN" \
  -up "$PASSWORD" \
  -il -w -s ExecuteBinaryWithInteractiveInput \
  definitionFile "$ARC_FILE" \
  archName "$ARC" \
  binaryFileToRun "$EXE" \
  ipRegStorageName ip \
  finishMnemonicName hlt \
  codeRamBankName code \
  stdinRegStName rin \
  stdoutRegStName rout
