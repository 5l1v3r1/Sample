// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // Null���e�^�ϐ��̏�����.
        int? x1 = null;    // x1��null�ŏ�����.
        int? x2 = 10;   // x2��10�ɏ�����.

        // x1�̏o��.
        if (x1.HasValue)    // �����Ă����.(null�łȂ����.)
        {
            Console.WriteLine("x1 = " + x1.Value);  // x1.Value���o��.
        }
        else   // �����ĂȂ�.(null)
        {
            Console.WriteLine("x1 has not Value.");  // x1.Value���o��.
        }

        // x2�̏o��.
        if (x2.HasValue)    // �����Ă����.(null�łȂ����.)
        {
            Console.WriteLine("x2 = " + x2.Value);  // x2.Value���o��.
        }
        else   // �����ĂȂ�.(null)
        {
            Console.WriteLine("x2 has not Value.");  // x2.Value���o��.
        }

    }

}