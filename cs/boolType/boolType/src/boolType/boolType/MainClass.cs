// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // bool�^�ϐ��̐錾�Ə�����.
        bool b1;    // bool�^�ϐ�b1�̐錾.
        bool b2 = false;    // bool�^�ϐ�b2��false�ɏ�����.
        bool b3;    // bool�^�ϐ�b3�̐錾.
        int x = 10; // int�^�ϐ�x��10�ɏ�����.

        // bool�^�ϐ��ւ̑��.
        b1 = true;  // b1��true����.

        // bool�^�ϐ��̏o��.
        System.Console.WriteLine("b1 = " + b1); // System.Console.WriteLine��b1���o��.
        System.Console.WriteLine("b2 = " + b2); // System.Console.WriteLine��b2���o��.

        // �������̐^�U
        b3 = x == 10;   // x��10���ǂ����̐^�U��b3�Ɋi�[.
        System.Console.WriteLine("b3 = " + b3); // System.Console.WriteLine��b3���o��.

        // if���ł̔���
        if (b3) // b3���^
        {
            System.Console.WriteLine("b3 is " + b3 + " !"); // System.Console.WriteLine��"b3 is True !"���o��.
        }

    }
}