
# Ex2_OperatingSystem


# implement two small programs, that fills like a regular CMD tools.

# Tool 1: “cmp”

The tool will compare two files, and return “0” if they are equal, and “1” if not (return an INT).
The tool will support -v flag for verbose output.
By this we mean that the tool will print “equal” or “distinct”, in addition to returning the int value.

The toll will support -i flag, that mean “ignore case” so “AAA” and “aaa” meaning equals

# usage: cmp <file1> <file2> -v
output: equal

![Screenshot from 2023-04-04 01-15-43](https://user-images.githubusercontent.com/92846018/229640298-0a7c9991-cc1d-4648-86c3-60465e707d2b.png)



# copy, the tool will copy a file to another place and/or name.  
The tool will return “0” on success, or “1” on failure (return an INT)
The tool will create a new file, if it does not exist, but it will not overwrite a file if it do exist.
  
The tool will support -v flag, that will output “success” if the file is copied, or “target file exist” if this is
the case, or “general failure” on some other problem (in addition to the returned INT value).
  
The tool will support -f flag (that means force), that allows to overwrite the target file.
  
  <div> usage copy <file1> <file2> -v </div>
    
output: success

![Screenshot from 2023-04-04 01-21-12](https://user-images.githubusercontent.com/92846018/229640328-0861b43b-1306-4172-8f86-884aafdc80e1.png)



    
    <div> implement a coding library. We have two codding methods. </div>
    
    
Method a, named codecA: covert all lower case chars to upper case, and all upper case to lower case.
All other chars will remain unchanged.
    
Method b, named codecB: convert all chars to the 3-rd next char (adding a number of 3 to the ascii val).
The libraries should support “encode” and “decode” methods.
    
<div> Note: the libraries should be “reversable”, meaning that if one does “encode” and then “decode, he will get the original string. </div>

    
There 2 different shared libraries , each implementing it’s algorithm
two tools, named encode and decode, to utilize the libraries. The tools will get some text and
convert it according to selected library.
    
    
    <div> 
      
Usage : encode/decode <codec> <message> 
      
output: encoded/decoded string
      
example: “encode codecA aaaBBB” will return “AAAbbb”
      
example: “decode codecB EEEddd” will return “BBBaaa”

      </div> 

![Screenshot from 2023-04-04 01-05-05](https://user-images.githubusercontent.com/92846018/229640406-f27c2dec-f28f-4264-a5b6-476fc840c72f.png)



