import java.io.*;
import java.util.Random;
public class float随机生成 {
    public static void main(String[] args) throws IOException {
        int size = (int) Math.pow(10000,2);
        Random rdm = new Random();
        File matrix1 = new File("C:\\Users\\27449\\IdeaProjects\\lab8e_A\\src\\1k");
        FileWriter fl = new FileWriter(matrix1);
        for (int i = 0;i<size;i++){
            fl.write(rdm.nextFloat(100000)+"f,");
        }
        fl.close();
    }
}
