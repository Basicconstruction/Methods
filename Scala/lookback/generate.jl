x = 1:30 
f = open("AtomList.scala","w")
for i in x
    write(f,"Atom$(i): \n")
end
close(f)