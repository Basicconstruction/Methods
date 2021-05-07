package com.tianyu.a1;

import javax.swing.*;
import java.util.concurrent.TimeUnit;

public class Gu1 {
    public static void main(String[] args) throws InterruptedException {
        JFrame frame = new JFrame("Hello swing!");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel j1 = new JLabel("a label");
        frame.add(j1);
        frame.setSize(300,300);
        frame.setVisible(true);
        TimeUnit.SECONDS.sleep(1);
        j1.setText("hey, this is a label");

    }
}
