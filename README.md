set_param('simulinkBitalino','EnableLBRepository','on');



# README simulinkBitalino module

This block reads measurements from a [BITalino](https://bitalino.com/en/) 'DYI physiology' device via Bluetooth.

Only tested on Windows.

- Bitalino code from: https://github.com/BITalinoWorld/cpp-api

## Workflow
- The basis of the module is the s-function generator on Matlab: `simulinkBitalino_dev.slx`
  - The block in this model will create the files `simulinkBitalino.cpp` and `simulinkBitalino_wrapper.cpp`
  - Do **not** edit these files.
  - Exclusively edit the custom code in `simulinkBitalino_mycode.cpp`
- Compile the code either from within `simulinkBitalino_dev.slx` or using `compile.bat`
- The library file is `simulinkBitalino.slx`

- "If you want the library to appear in the Library Browser, enable the model property EnableLBRepository before you save the library."
   `set_param(gcs,'EnableLBRepository','on');`

## Install
- Default location is `%USERPROFILE%\Documents\MATLAB\simulinkBitalino`


