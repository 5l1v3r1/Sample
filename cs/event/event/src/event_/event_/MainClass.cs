// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ���̓`�F�b�N
        InputCheckClass chk = new InputCheckClass("abc");   // InputCheckClass�I�u�W�F�N�gchk�𐶐�.
        chk.callback += new EventDelegate(EventHandler);    // chk.callback��EventHandler��ǉ�.
        chk.InputCheckLoop();   // �`�F�b�N���[�v�ɓ���.
        Console.WriteLine("(End)"); // "(End)"�Əo��.

    }

    // �n���h��
    static void EventHandler(string inputString)
    {

        // �q�b�g�������Ƃ��o��.
        Console.WriteLine("Hit!: " + inputString);  // "Hit!"��inputString���o��.

    }

}