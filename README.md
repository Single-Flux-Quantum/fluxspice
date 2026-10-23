# FluxSPICE™ Standalone Binary Release

> **Version:** `v0.1.0`  
> **Target:** Superconducting VLSI Circuits (RSFQ, ERSFQ, AQFP)  
> **Engine:** Pure-ODE Phase State Formulation with Dense/Projected Loop Tensor and Ring-Buffer Rollback

---

## 1. Directory Structure

```text
release/
├── bin/
│   ├── fluxspice-cli.exe      # High-performance C++20 simulation binary (Windows)
│   ├── test_fluxspice.exe     # Standalone regression verification binary
│   └── libomp.dll             # OpenMP multi-threading runtime
├── circuits/
│   ├── c17.cir                # ISCAS-85 c17 benchmark (81 JJs)
│   ├── alu.cir                # SFQ Arithmetic Logic Unit (102 JJs)
│   ├── brent_kung_4b.cir      # 4-bit Brent-Kung adder (198 JJs)
│   ├── brent_kung_8b.cir      # 8-bit Brent-Kung adder (505 JJs)
│   ├── gray_counter.cir       # SFQ Gray code counter (137 JJs)
│   ├── shift_register_left.cir# Synchronous shift register (110 JJs)
│   ├── kogge_stone_4b.cir     # 4-bit Kogge-Stone adder (186 JJs)
│   └── carry_lookahead_4b.cir # 4-bit Carry Lookahead adder (81 JJs)
├── pdk/
│   ├── mitll_sfq5ee_cells.inc # MIT-LL SFQ5ee PDK standard cell SPICE library
│   └── mitll_sfq5ee.json      # PDK electrical and process parameter deck
├── docs/
│   ├── REPORT.md              # Detailed regression benchmark and simulation report
│   └── figures/               # Multi-core scaling & throughput benchmark figures
├── run_samples.bat            # Automated Windows sample execution script
└── run_samples.sh             # Automated Unix/Linux sample execution script
```

---

## 2. Quick Start

### Running Sample Simulations on Windows:
```cmd
.\run_samples.bat
```

### Running Standalone Simulation:
```cmd
.\bin\fluxspice-cli.exe -v -t 4 -o output.csv circuits\c17.cir
```

### CLI Command Options:
- `-o <file.csv>`: Specify output CSV waveform file (default: `output.csv`)
- `-t, --threads <N>`: Set number of CPU OpenMP threads (default: 1)
- `-v, --verbose`: Display full circuit node, branch, tree partition, and runtime telemetry
- `-h, --help`: Print help banner and options

---

## 3. Verification & Regressions
Run the regression test suite anytime directly from the binary distribution:
```cmd
.\bin\test_fluxspice.exe
```
All 6 primary architectural invariants (Ring-buffer rollback, Hermite spline interpolation, Graph spanning-tree partition, SFQ pulse area quantization $\Phi_0$, MIT-LL PDK cell ingestion, and ISCAS-85 benchmark transient solve) will execute and report pass status.
