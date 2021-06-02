#tips 项目\n",-*
#横向合成表格（两个）（excel）项目tip1\n",
#纵向合成表格（两个）（excel）项目tip2\n",
#将csv文件转化为excel文件项目tip3\n",
#将excel文件转化为csv文件项目tip4\n",
#随机数生成器tip6\n",<可修改>
#路径生成器tip5\n",
#等差数列求和tip7\n",
#等比数列求积tip8\n",
#读取csv文件数据并存储tip9\n",
#快速作图tip10(饼图，折线xy图，折线xyy图)\n",
#从自定X*X数据列表中选择一些数据tip11\n",<灵感来自numpy2_400及randomlearning>
import pandas as pd
import random
import time
import datetime
from tkinter import messagebox
import matplotlib.pyplot as plt
#tip3
#将csv文件转化为excel文件项目
def csvTxlsx(csvtrace) :        
    disk1 = pd.read_csv(csvtrace)
    name = 'ctefile%s.xlsx'%(random.randint(1,100))
    disk1.to_excel(name,index = True)
    print('csv转excel成功,请前往python文件目录下寻找{}文件'.format(name))
#tip4
#将excel文件转化为csv文件项目
def xlsxTcsv(exceltrace) :
    disk2 = pd.read_excel(exceltrace)
    name = 'etcfile%s.csv'%(random.randint(1,100))
    disk2.to_csv(name,index = False)
    print('excel转csv成功,请前往python文件目录下寻找{}文件'.format(name))
#tip2
#纵向合成表格（两个）（excel）项目
def concat2(excel1trace,excel2trace) :
    disk3 = pd.read_excel(excel1trace)
    disk4 = pd.read_excel(excel2trace)
    pn1 = pd.concat([disk3,disk4])
    name = 'ecefile%s.xlsx'%(random.randint(1,100))
    pn1.to_excel(name,index = True)
    print('excel文件合成成功，请前往python文件路径寻找{}文件'.format(name))
#tip1
#横向合成表格（两个）（excel）项目
def merge2(excel1trace,excel2trace) :
    disk5 = pd.read_excel(excel1trace)
    disk6 = pd.read_excel(excel2trace)
    pn2 = pd.merge(disk5,disk6,how = 'outer')
    name = 'emefile%s.xlsx'%(random.randint(1,100))
    pn2.to_excel(name,index = True)
    print('excel文件合成成功，请前往python文件路径寻找{}文件'.format(name))
#tip5
#路径生成器
def tracesmaker(maintrace,likename,n,typename) :
    traces = []
    for i in range(n) :
        trans1 ='\'{}{}{}{}\''.format(maintrace,likename,i,typename)
        trans2 = 'r' + trans1
        traces.append(trans2)
    for i in traces :
        print(i)
#tip6
#随机数生成器
def randomintnummaker(min,max) :
    x = int(time.time())
    y = random.randint(min,max)
    z = x % 100
    a = z % 10
    b = int(a / 5)
    s = y + a - b
    list1 = []
    #z为根据当前时间求得的数
    for i in range(min,max+1) :
        list1.append(i)
    while s not in list1 :
        s = s - a + b
    else :
        print(s)
#tip7
#等差数列求和
def sumDCL(a,d,n) :
    i = 1
    sum = 0
    while i <= n :
        item0 = a + (i - 1) * d
        sum = sum + item0
        i = i + 1
    print(sum)
#tip8
#等比数列求积
def mulDBL(a,q,n) :
    i = 1
    summul = 1
    if (q != 1) &(q != 0) :
        while i <= n :
            item1 = a *(q**(i -1))
            summul = summul * item1
            i = i + 1
        print(summul)
    elif q == 1 :
        print(a)
    else :
        messagebox.showerror('Valueerror','请检查你输入的数据，公比不能为零哟')
#tip10
#快速作图
def showPie(labels,datas,title,isLegend):
    plt.rcParams['font.family'] = ['SimHei']
    plt.pie(datas,labels = labels,aotupct = "%0.1f%%")
    if isLegend :
        plt.legend()
    plt.title(title)
    plt.show()
def showFoldxy(xs,ys,title,label,isLegend,havelabels) :
    plt.rcParams['font.family'] = ['SimHei']
    x = xs
    y = ys
    if havelabels :
        xlabel = input('请输入xlabel')
        ylabel = input('请输入ylabel')
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    if label :
        label = input('请输入y相关label')
    plt.plot(x,y,label = label)
    if isLegend :
        plt.legend()
    plt.title(title)
    plt.show()
def showFoldxyy(xs,ys1,ys2,title,labels,isLegend,havelabels) :
    plt.rcParams['font.family'] = ['SimHei']
    x = xs
    y1 = ys1
    y2 = ys2
    if havelabels :
        xlabel = input('请输入xlabel')
        ylabel = input('请输入ylabel')
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    if labels :
        labela = input('请输入y1相关label')
        labelb = input('请输入y2相关label')
    plt.plot(x,y1,label = labela)
    plt.plot(x,y2,label = labelb)
    if isLegend :
        plt.legend()
    plt.title(title)
    plt.show()
#tip11
#随机数列生成（+）
#外加一个辅助函数，可用于返回一个X*X数据列表
def numpys(s) :
    listq = []
    for i in range(s+1) :
        for a in range(s+1) :
            hence = [i,a]
            listq.append(hence)
    return listq
def numpys2(s) :
    listq = []
    i = -s
    a = -s
    list1 = []
    while i <= s :
        list1.append(i)
        i = i + 1    
    for i in list1 :
        for a in list1 :
            listq.append([i,a])
    return listq
print(numpys2(3))
def randomlistmake(n,k) :
    list1 = numpys(n)
    listreturn = []
    for i in range(k) :
        listreturn.append(random.choice(list1))
    return 
def randomlistmake2(n,k) :
    list1 = numpys2(n)
    listreturn = []
    for i in range(k) :
        listreturn.append(random.choice(list1))
    return listreturn