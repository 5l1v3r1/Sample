// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �f���Q�[�g�̒�`.
delegate int AddDelegate(int a, int b); // ������int�^��a, b, �߂�l��int�^�̃��\�b�h�����f���Q�[�gAddDelegate.

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �������\�b�h�̐���.
        AddDelegate add = delegate(int a, int b)    // ���O�̖���AddDelegate�^���\�b�h���`��, add�Ɋi�[.
        {

            // a��b�𑫂����l��Ԃ�.
            return a + b;   // a + b��Ԃ�.

        };

        // add�����������\�b�h�����s.
        int result = add(10, 20);   // add��10��20��n��, ���ʂ�result�Ɋi�[.

        // ���ʂ̏o��.
        Console.WriteLine("result = " + result);    // resul�̒l���o��.

    }

}