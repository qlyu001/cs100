#!/bin/sh

cat "niharika_861165007.txt" > $1.cs
echo "#ifndef MyClass_hh" >> $1.cs
echo -e "#define MyClasss_hh" >> $1.cs
echo -e "/n" >> $1.cs
echo -e "class MyClass" >> $1.cs
echo -e "{" >> $1.cs
echo -e "public:" >> $1.cs
echo -e "MyClass();" >> $1.cs
echo -e "~MyClass();" >> $1.cs
echo -e "/n" >> $1.cs
echo -e "private:" >> $1.cs
echo -e "};" >> $1.cs
echo "#endif" >> $1.cs

cat "niharika_861165007.txt" > $1.hh
echo "#include "./MyClass.hh"" >> $1.hh
echo -e "/n" >> $1.hh
echo -e "MyClass::MyClass\(\)" >> $1.hh
echo  "{}" >> $1.hh
echo -e "/n" >> $1.hh
echo -e "MyClass::~MyClass\(\)" >> $1.hh
echo -e "\{\}" >> $1.hh
