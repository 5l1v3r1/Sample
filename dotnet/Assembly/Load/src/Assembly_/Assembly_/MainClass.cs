// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Reflection;    // ���t���N�V����(System.Reflection���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ClassLibrary�̃��[�h.
        try
        {

            // "ClassLibrary"�̃��[�h.
            Assembly asm1 = Assembly.Load("ClassLibrary");   // Assembly.Load��"ClassLibrary"�����[�h.
            Console.WriteLine("asm1 = " + asm1);  // asm1���o��.

        }
        catch (Exception ex)    // ��O����
        {

            // ��O�o��
            Console.WriteLine(ex.ToString());   // ex.ToString���o��.

        }

    }

}