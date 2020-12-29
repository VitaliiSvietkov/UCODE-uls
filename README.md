<p align="center">My own implementation of the Unix 'ls' command</p>

<hr>

## Building the program

1. Clone the source code
2. Move to the root directory
3. Run `make` command

<p>
To delete the program run `make uninstall` command</br>
To delete all 'obj' files - `make clean`</br>
To reinstall the program - `make reinstall`</br>
</p>

## Running the program

Call `./uls` from the root directory of the source code after building it.

## Supported flags
```
usage: uls [-1AaCfGilmoprSsTt] [file ...]
```

## --help
```
     If no operands are given, the contents of the current directory are dis-
     played.  If more than one operand is given, non-directory operands are
     displayed first; directory and non-directory operands are sorted sepa-
     rately and in lexicographical order.

     The following options are available:

     -1      (The numeric digit ``one''.)  Force output to be one entry per
             line.  This is the default when output is not to a terminal.

     -A      List all entries except for . and .. .  Always set for the super-
             user.

     -a      Include directory entries whose names begin with a dot (.).

     -C      Force multi-column output; this is the default when output is to
             a terminal.
             
     -F      Display a slash (`/') immediately after each pathname that is a
             directory, an asterisk (`*') after each that is executable, an at
             sign (`@') after each symbolic link, an equals sign (`=') after
             each socket, a percent sign (`%') after each whiteout, and a ver-
             tical bar (`|') after each that is a FIFO.

     -f      Output is not sorted.  This option turns on the -a option.

     -G      Enable colorized output.  This option is equivalent to defining
             CLICOLOR in the environment.  (See below.)

     -i      For each file, print the file's file serial number (inode num-
             ber).

     -l      (The lowercase letter ``ell''.)  List in long format.  (See
             below.)  If the output is to a terminal, a total sum for all the
             file sizes is output on a line before the long listing.

     -m      Stream output format; list files across the page, separated by
             commas.

     -o      List in long format, but omit the group id.

     -p      Write a slash (`/') after each filename if that file is a direc-
             tory.

     -r      Reverse the order of the sort to get reverse lexicographical
             order or the oldest entries first (or largest files last, if com-
             bined with sort by size

     -S      Sort files by size

     -s      Display the number of file system blocks actually used by each
             file, in units of 512 bytes, where partial units are rounded up
             to the next integer value.  If the output is to a terminal, a
             total sum for all the file sizes is output on a line before the
             listing.  The environment variable BLOCKSIZE overrides the unit
             size of 512 bytes.

     -T      When used with the -l (lowercase letter ``ell'') option, display
             complete time information for the file, including month, day,
             hour, minute, second, and year.

     -t      Sort by time modified (most recently modified first) before sort-
             ing the operands by lexicographical order.

     -x      The same as -C, except that the multi-column output is produced
             with entries sorted across, rather than down, the columns.

     The -1, -C, -x, and -l options all override each other; the last one
     specified determines the format used.

     The -c and -u options override each other; the last one specified deter-
     mines the file time used.

     By default, ls lists one entry per line to standard output; the excep-
     tions are to terminals or when the -C or -x options are specified.
```
