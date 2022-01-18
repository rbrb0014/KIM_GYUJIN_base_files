package JavaGUI;

import java.awt.Frame;

public class FrameTest extends Frame {
    public FrameTest() {
        super("두 번째 프레임입니다.");
        setBounds(100, 100, 500, 300);
        setVisible(true);
    }

    public static void main(String args[]) {
        FrameTest Obj = new FrameTest(); // FrameTest 클래스 obj 객체 선언
    }
}