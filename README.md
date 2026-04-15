<div align="center">

# HexSight

![C++](https://img.shields.io/badge/C++-17-blue?style=flat&logo=c%2B%2B)
![License](https://img.shields.io/badge/License-MIT-green)
![Type](https://img.shields.io/badge/Type-Forensics-orange)

<p>
  <strong>A CLI-based Hex Viewer for binary file analysis.</strong>
</p>

[Report Bug](https://github.com/egetones/hexsight/issues) · [Request Feature](https://github.com/egetones/hexsight/issues)

</div>

---

## Description

**HexSight** is a lightweight forensic tool written in C++. It allows security researchers to view the raw binary content of any file in a human-readable hexadecimal format.

Understanding the raw bytes is crucial for malware analysis, reverse engineering, and file format verification. HexSight mimics the output of standard tools like `hexdump -C` but offers a customizable and colorized output for better readability.

### Key Features

  **Colorized Output:** Distinct colors for Offsets, Hex Bytes, and ASCII characters.
  **Deep Inspection:** Reveals hidden non-printable characters using a safe filter.
  **Fast:** Buffer-based reading allows scanning large files efficiently.

---

## Installation & Usage

1. **Compile:**
   ```bash
   make
   ```

2. **Run:**
   ```bash
   ./hexsight <filename>
   ```

### Example Output
Analyzing a simple text file or a binary (`.exe`, `.jpg`):

```text
OFFSET    | HEX BYTES                                       | ASCII
-----------------------------------------------------------------
00000000  48 65 6c 6c 6f 20 57 6f  72 6c 64 21 0a           |Hello World!.|
00000010  de ad be ef 00 00 00 00  ...                      |....|
```

---

## License

Distributed under the MIT License. See `LICENSE` for more information.
