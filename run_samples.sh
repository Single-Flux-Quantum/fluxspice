#!/usr/bin/env bash
set -e

echo "======================================================================="
echo "         FluxSPICE™: Official Sample Simulation Runner (Unix)          "
echo "======================================================================="

CLI_BIN=""
if [ -f "bin/fluxspice-cli" ]; then
    CLI_BIN="bin/fluxspice-cli"
elif [ -f "../build/fluxspice-cli" ]; then
    CLI_BIN="../build/fluxspice-cli"
elif [ -f "fluxspice-cli" ]; then
    CLI_BIN="./fluxspice-cli"
fi

if [ -z "$CLI_BIN" ]; then
    echo "[ERROR] No binary found. Please compile first using cmake or ninja."
    exit 1
fi

echo "[*] Using CLI binary: $CLI_BIN"
echo ""

mkdir -p sample_waveforms

echo "[SAMPLE 1] Simulating ISCAS-85 c17 Benchmark (81 JJs) [Threads=1]..."
$CLI_BIN -v -t 1 -o sample_waveforms/c17_waveforms.csv circuits/c17.cir
echo "[+] Sample 1 PASSED."
echo ""

echo "[SAMPLE 2] Simulating SFQ ALU Core (102 JJs) [Threads=1]..."
$CLI_BIN -v -t 1 -o sample_waveforms/alu_waveforms.csv circuits/alu.cir
echo "[+] Sample 2 PASSED."
echo ""

echo "[SAMPLE 3] Simulating Brent-Kung 4-bit Parallel Prefix Adder (198 JJs) [Threads=4]..."
$CLI_BIN -v -t 4 -o sample_waveforms/brent_kung_waveforms.csv circuits/brent_kung_4b.cir
echo "[+] Sample 3 PASSED."
echo ""

echo "[SAMPLE 4] Simulating Synchronous Shift Register (110 JJs) [Threads=2]..."
$CLI_BIN -v -t 2 -o sample_waveforms/shift_reg_waveforms.csv circuits/shift_register_left.cir
echo "[+] Sample 4 PASSED."
echo ""

echo "[SAMPLE 5] Simulating Kogge-Stone 4-bit Fast Adder (186 JJs) [Threads=8]..."
$CLI_BIN -v -t 8 -o sample_waveforms/kogge_stone_waveforms.csv circuits/kogge_stone_4b.cir
echo "[+] Sample 5 PASSED."
echo ""

echo "======================================================================="
echo "  [SUCCESS] All 5 FluxSPICE sample simulations completed cleanly!      "
echo "  Waveform CSV traces exported to: sample_waveforms/                   "
echo "======================================================================="
exit 0
