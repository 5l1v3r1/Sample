// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // object�^��Object�N���X�̃C���X�^���X����.
        object objType = new object();  // object�^objType��new object()�Ő���.
        Object objClass = new Object(); // Object�N���XobjClass��new Object()�Ő���.

        // �^(�N���X)�����o��.
        Console.WriteLine("objType: " + objType.GetType().ToString());  // objType.GetType().ToString()�Ŏ擾�ł���^�����o��.
        Console.WriteLine("objClass: " + objClass.GetType().ToString());    // objClass.GetType().ToString()�Ŏ擾�ł���N���X�����o��.

    }

}