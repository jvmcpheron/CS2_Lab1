# CS2_Lab1

## Working with Polymorphic Types
Introduction
As a data guy, your professor really wants you to start being easily able to read in big files of data so that we can manipulate said files.  One of the easiest ways to provide data is to use the simple spreadsheet format called a CSV (Comma Separated Value) file (for example, if you go into MS Excel you can create a spreadsheet and then save it Save As option as a CSV file).  For example, if I had a matrix of data with 4 rows and 3 columns that had random numbers between 1 and 100 it might look like this:

42,37,4
89,19,28
55,61,5
79,98,31

C++ does not have a native library for reading in such files (you can find some from projects online) but you can easily write something that does a lot of the job.  And I have done so.  You can find my basic code in this file Download this file.

But the code as is simply assumes that all of the values in the file are strings.  Most of the time we actually expect such a file to contain numbers (though often they do have a mix of numbers and strings).  It is also useful to know when NO value was entered for an item in the spreadsheet (rather than having an empty string).

## What to Implement
I want you to design a polymorphic type.  The base type should be named SElement (Spreadsheet Element).  You should then have 4 derived types:

EmptyValue - this spreadsheet entry has no value
IntegerValue - this spreadsheet entry has an integer value
FloatValue - this spreadsheet entry has a floating point value
StringValue - this spreadsheet entry has a string value
You should write a routine showValueAndType that is implemented in all of these types and prints the type and value of that entry.

So, if you CSV file contained

,xyz,5
-2.3,42,
5,"5",",,"

Then if you printed out the values one at a time using the showValueAndType routine you would get:

Empty String(xyz) Int(5)
Float(-2.3) Int(42) Empty
Int(5) String("5") String(",,")

## What To Turn In
You should submit your revised coding file.  You should also submit a CSV file that you think properly tests your code and the results produced for that test file.