# The rxv64 Operating System

rxv64 is a pedagogical operating system written in Rust that targets
multiprocessor x86_64 machines. It is a reimplementation of the xv6
operating system from MIT.

As a pedagogical system, it supports very little hardware other than
the text-mode CGA device, serial port, PS/2 keyboard controller, and
PCIe AHCI SATA storage devices.

See the xv6 README for more information on provenance and intended
use.

## Usage

- Ensure QEMU is installed if you want to virtualize rxv64. The [QEMU Homepage](https://www.qemu.org/download/)
  has install instructions for building or installing for a number of target
  operating systems.
- `ld.lld` is required for building user programs. On Ubuntu this can be installed with

```bash
sudo apt-get install lld
```

1. Build mkfs

```bash
cd bin
make mkfs
```

2. Make `sdahci0.img`

```bash
dd if=/dev/zero of=sdahci0.img bs=1M count=1024
```

This creates a blank image for QEMU to use. This command
will initialize `sdahci0.img` as a 1 gigabyte file full of
null bytes.

3. Build, run, or test

```bash
cargo xtask build
cargo xtask run # Runs rxv64 virtually in QEMU
cargo xtask test # Runs unit tests
```

4. Build user programs

```bash
cd bin
sh mk
```

### Troubleshooting

While attempting to `test`/`build`/`run` received:

```bash
error: failed to install component: 'rust-src', detected conflict: 'lib/rustlib/src/rust/Cargo.lock'
```

Resolved by reinstalling the nightly toolchain

```bash
rustup toolchain remove nightly-x86_64-unknown-linux-gnu
rustup install nightly-x86_64-unknown-linux-gnu
```