# OLink

 
 **OLink** takes the output files from compilers and assemblers, and merges them together.  This merging is necessary because often a single source file will either declare 'global' code or data that is accessible from other source files, or reference such global data from another file.  Each output file from a compiler or assembler will have a list of these kinds of declarations, and the linker has two tasks:  to combine the actual code and data from different files, and to resolve these global references between files.
 
 When it comes to the actual data being combined, the compiler or assembler will organize the code and data into **sections**.  Each section has a name, and this name is one of the criteria used in combining section data.  For example a code section might contain the code fragments from the file, an initialized data section might hold initialized data, and an uninitialized data section might reserve space for uninitialized data.  In compiler output, other sections might occur for example to hold constant data, string data, or control information.  An assembly program can directly control the segmentation of code and data into sections, and any number of arbitrary sections may appear according to the needs of the program.
 
 It should be stressed that OLink does not generate actual ROM images or executable files; all it does is combine code and data, and resolve the global references.  Another post-processing program is used to generate the ROM image or executable file, based on the output of **OLink**.
 
 The output of **OLink** can be guided through use of a [specification file](OLink%20Specification%20Files.md) and through command-line defines.  The specification file indicates the ordering and grouping of sections, and gives default addresses and other attributes to the groupings.  Command-line defines can be used to taylor the specifics of how the specification file is used; in OLink the command line defines generally act in terms of giving an absolute address to a variable which has been referenced elsewhere.


## Command Line Options

 The general form of an **OLink **[Command Line](OLink%20Command%20Line%20Options.md) is:
 
> OLink \[options\] filename-list
 
 Where _filename-list_ gives a list of files to merge together.  **OLink** natively understands files of the extension **.o** and **.l**, when generated by other tools in this package.  Generally it will pass other files specified on the command line to a ROM-Image or EXE-Building tool for further analysis.  For example **.res** (windows resource) files are passed on to DLPE to help it build the executable.
 
 **Olink** takes the files in _filename-list_, and produces an output file with a **.rel **extension.


## Specification Files

 [Specification files](OLink%20Specification%20Files.md) give a flexible method for specifying how to merge sections from the various input files.  They can specify what code and data be combined together, in what order, and what the address of code and data should be.  A specification file uses three basic constructs, and each construct can be further clarified with attributes.  
 
 At the top level there can be one or more **Partitions**.   Each partition can be relocated independently of other partitions.  
 
 A partition contains one or more **Overlays**.  The overlays are independendent units of code or data, which are overlayed onto a common region of memory.  The overlay mechanism can be used for example in systems that need to use bank-switching to extend the amount of memory available.  
 
 An overlay contains **Regions**, which simply specify the names of sections that should be combined together.  The regions can be actual section names, or expressions containing section names.  Normally a region would contain all sections matching the section name from all input files, but, a Region can be further clarified with a list of files that should be considered for inclusion.  In this way different files with the same section can be combined into different overlays.


## Target Configurations

 
  [Target configurations](OLink%20Target%20Configurations.md) specify the default mechanism for taking the linker output and creating a ROM image or executable file.  Each target configuration specifies a linker specification file, a list of default definitions, and the name of a post-processing program such as **DLHex** to run to create the final output file.  The specification files used with default target configurations are generic in nature, and make certain assumptions about the program; however some of the identifiers in such specification filse may refer to definitions made elsewhere.  Those definitions are generally part of the target configuration, and may be modified through command-line options to make minor changes to the configuration.  For example, in WIN32 DLLs, the base address of the DLL may be redefined via the command line to not collide with other DLLs and thus improve load time.
 
 
   