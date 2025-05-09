# Aero - Voxel Engine for Windows
Aero is a low-level voxel engine built using Windows API for direct system interaction. 
Unlike a traditional game framework, it operates by directly calling system functions and bypassing higher-level libraries or runtimes. 
This approach gives developers more control over how the system resources are managed and utilized, providing a more "bare-metal" experience in voxel-based 3D rendering.

# System Requirements
- OS: Windows 10/11 64-bit
- CPU: SSE 4.2 support required
- RAM: 4 GB DDR4
- GPU: OpenGL 4.0
- Storage: Using SSD is Recommended

# Features
- [ ] Accelerated Compute World Generation
- [ ] Accelerated Compute Shader Generation
- [ ] World Planet Gravity Object
- [ ] Object Culling
- [ ] Embedded Media Assets with Windows CNG Protection

# Libraries, Toolchains & Programming Language
- [x] Windows API (10.0.26100.0)
- [x] Windows Codec API
- [x] OpenGL 4
- [x] Clang/LLVM (17.0.5)
- [ ] SPIR-V
- [x] KTX
- [x] SSE4.2
- [x] AVX2
- [x] C/C++ without UCRT & STD C++
- [x] Makefile

# Notes
- If you are looking for media file such as audio files, image files, or similar like this it doesn't available in releases binary.
- This project still under developments. Contribution and feedback are welcome!
