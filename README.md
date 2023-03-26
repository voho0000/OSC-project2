# OSC-project2

## Run
- Environment: Linux  
- Run  
  `make # Build the kernel module`    
  - Test hello_module  
  `sudo insmod hello_module.ko #Load the kernel module`  
  `sudo rmmod hello_module # Unload the kernel module`  
  `dmesg #check the kernel log buffer`  
   
  - Test birthday_module  
  `sudo insmod birthday_module.ko #Load the kernel module`  
  `sudo rmmod birthday_module # Unload the kernel module`  
  `dmesg #check the kernel log buffer`  
