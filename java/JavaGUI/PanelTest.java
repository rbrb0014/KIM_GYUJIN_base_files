package JavaGUI;

import java.awt.*;

public class PanelTest extends Frame {
    public PanelTest(String str) {
        super(str);
        Panel panel1 = new Panel();
        // 색을 빨강으로 지정
        panel1.setBackground(Color.RED);
        // 추가
        add(panel1);
        // 크기
        setSize(300, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new PanelTest("패널 테스트");
    }
}