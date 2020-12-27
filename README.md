<p align="center">My own implementation of the Unix 'ls' command</p>

<hr>

## Building the program

1. Clone the source code
2. Move to the root directory
3. Run `make` command

<p>
To delete the program run 'make uninstall' command</br>
To delete all 'obj' files - 'make clean'</br>
To reinstall the program - 'make reinstall'</br>
</p>

## Running the program

Call `./uls` from the root directory of the source code after building it.

## Supported flags
```
usage: uls [-1AaCfGlprSst] [file ...]
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

     -l      (The lowercase letter ``ell''.)  List in long format.  (See
             below.)  If the output is to a terminal, a total sum for all the
             file sizes is output on a line before the long listing.

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

     -t      Sort by time modified (most recently modified first) before sort-
             ing the operands by lexicographical order.

     The -1, -C, -x, and -l options all override each other; the last one
     specified determines the format used.

     The -c and -u options override each other; the last one specified deter-
     mines the file time used.

     The -B, -b, -w, and -q options all override each other; the last one
     specified determines the format used for non-printable characters.

     The -H, -L and -P options all override each other (either partially or
     fully); they are applied in the order specified.

     By default, ls lists one entry per line to standard output; the excep-
     tions are to terminals or when the -C or -x options are specified.
```

## Author
<p align="center">
    <a href="https://github.com/VitaliiSvietkov" target="_blank">
        <img src="https://avatars3.githubusercontent.com/u/61375757?s=460&u=0bbb6bba911c39806ee1e3de6a3b34f093279545&v=4" height="100px">
    </a>
</p>
<p align="center">
<a href="https://github.com/VitaliiSvietkov" target="_blank">Vitalii Svietkov</a>
</p>
