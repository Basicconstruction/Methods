import os
oldname = input("请输入路径以及文件名")
i = -1
while (oldname[i]!="\\"):
    i = i -1
path = oldname[:i+1]
newname = input("请输入新的文件名")
newname = path + newname
print(newname)
os.rename(oldname,newname)
#待增加，提高可视性与逻辑