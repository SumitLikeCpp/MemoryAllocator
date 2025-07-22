# Memory Allocator

A custom memory allocator implementation in C with assembly language support, designed to manage a 1GB heap space efficiently using a word-based allocation system.

## 🎯 Concept

This memory allocator implements a custom heap management system with the following key concepts:

### Memory Layout
- **Heap Size**: 1 GB (1024³ bytes) of pre-allocated memory space
- **Word Size**: 4 bytes (32 bits) - the smallest allocation unit
- **Total Words**: ~268 million words (1GB ÷ 4 bytes)
- **Addressing**: Words are numbered from 0 to ~268M

### Allocation Structure
- **Minimum Allocation**: 8 bytes (2 words)
  - 1st word: Header containing metadata
  - 2nd+ words: Actual usable memory
- **Header Format**: Each allocation has its own header with packed structure

### Header Structure (32-bit word)
```c
struct s_header {
    word w:30;        // Number of words in allocation (30 bits)
    bool alloced:1;   // Allocation status (1 bit)
    bool reserved:1;  // Reserved for future use (1 bit)
} __attribute__((__packed__));
```

## 🏗️ Architecture

### Core Components

1. **alloc.h** - Header file containing:
   - Type definitions and aliases
   - Memory structure definitions
   - Function prototypes
   - Compiler attributes and macros

2. **alloc.c** - Main implementation:
   - Memory allocation functions
   - Heap management logic
   - Utility functions

3. **heap.asm** - Assembly implementation:
   - Low-level memory space definition
   - 1GB heap space allocation
   - Platform-specific optimizations

### Key Features

- **Custom Type System**: Defined types for different word sizes (int8, int16, int32, int64)
- **Packed Structures**: Memory-efficient header storage
- **Assembly Integration**: Low-level memory management
- **Error Handling**: Built-in memory exhaustion detection

## 🚀 Getting Started

### Prerequisites

Make sure you have the following installed on your Ubuntu Linux system:

```bash
# Install build essentials
sudo apt update
sudo apt install build-essential

# Install NASM (Netwide Assembler)
sudo apt install nasm

# Install GCC compiler
sudo apt install gcc
```

### Building the Project

1. **Clone or download the project**:
   ```bash
   git clone https://github.com/SumitLikeCpp/MemoryAllocator.git
   cd MemoryAllocator
   ```

2. **Build using Make**:
   ```bash
   make
   ```

   This will:
   - Compile `alloc.c` to object file
   - Assemble `heap.asm` to object file  
   - Link both into the final `alloc` executable

3. **Clean build artifacts**:
   ```bash
   make clean
   ```

### Manual Build (Alternative)

If you prefer to build manually:

```bash
# Compile C source
gcc -O2 -Wall -std=c11 -c alloc.c

# Assemble the heap
nasm -f elf32 -o heap.o heap.asm

# Link everything
gcc -O2 -Wall -std=c11 alloc.o heap.o -o alloc
```

## 📋 Usage

### Basic Allocation

```c
#include "alloc.h"

int main() {
    // Allocate 12 bytes
    int8 *str = (int8 *)alloc(12);
    
    // Use the allocated memory
    strcpy(str, "Hello World");
    
    // Free when done
    destroy(str, 12);
    
    return 0;
}
```

### Convenience Functions

```c
// Allocate in kilobytes
void *ptr_kb = allock(4);  // 4KB allocation

// Allocate in megabytes  
void *ptr_mb = allocm(2);  // 2MB allocation

// Reallocate to change size
ptr_kb = realloc(ptr_kb, 8192);  // Resize to 8KB
```

## 🧪 Testing

The project includes test concepts in `test.h` that demonstrate:

- Memory allocation patterns
- Header structure validation
- Word-based addressing
- Error handling scenarios

To run tests:

```bash
# Build the project
make

# Run the executable
./alloc
```

## 📁 Project Structure

```
MemoryAllocator/
├── README.md          # This file
├── alloc.h           # Header definitions and types
├── alloc.c           # Main implementation
├── heap.asm          # Assembly heap definition
├── heap64bit.asm     # 64-bit assembly variant
├── test.h            # Testing concepts and examples
├── Makefile          # Build configuration
├── MakeFile          # Alternative build config
└── LICENSE           # License information
```

## 🔧 Technical Details

### Memory Management Strategy

1. **Pre-allocation**: 1GB heap space is allocated at startup
2. **Word-based**: All allocations are rounded up to word boundaries
3. **Header-prefixed**: Each allocation includes a metadata header
4. **Contiguous**: Memory is allocated in contiguous blocks
5. **First-fit**: Uses first available block that fits the request

### Platform Support

- **Primary**: Linux Ubuntu (32-bit and 64-bit)
- **Architecture**: x86/x86_64
- **Assembler**: NASM (Netwide Assembler)
- **Compiler**: GCC with C11 standard

### Performance Characteristics

- **Allocation Speed**: O(n) worst case (linear search)
- **Memory Overhead**: 4 bytes per allocation (header)
- **Fragmentation**: Minimal due to word-aligned allocations
- **Memory Usage**: Fixed 1GB heap size

## 🐛 Troubleshooting

### Common Issues

1. **NASM not found**:
   ```bash
   sudo apt install nasm
   ```

2. **Compilation errors**:
   - Ensure GCC supports C11 standard
   - Check that all source files are present

3. **Linking errors**:
   - Verify object files are generated correctly
   - Check makefile syntax

4. **Runtime errors**:
   - Ensure sufficient system memory (>1GB available)
   - Check for memory permission issues

## 📄 License

This project is licensed under the terms specified in the LICENSE file.

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly on Ubuntu Linux
5. Submit a pull request

## 📞 Support

For issues and questions:
- Check the troubleshooting section
- Review the test.h file for usage examples
- Ensure your Ubuntu system meets the prerequisites

---

**Note**: This allocator is designed for educational and experimental purposes. For production use, consider additional features like thread safety, memory protection, and advanced fragmentation handling.
