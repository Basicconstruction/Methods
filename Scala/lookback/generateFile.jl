//得益于julia高效及简单的文件IO操作，生成若干的文件是非常简单的
x = 1:20 
for i in x
    f = open("Atom$(i).scala","w")
    str = """
    /*
    
    */
    object Atom$(i){
        def main(args:Array[String]){

        }
    }
    
    
    """
    write(f,str)
    close(f)
end