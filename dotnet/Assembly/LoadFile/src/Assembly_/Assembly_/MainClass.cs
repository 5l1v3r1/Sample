// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Reflection;    // ���t���N�V����(System.Reflection���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ��΃p�X.
    public const string PATH1 = @""; // ��΃p�XPATH1��ݒ�.
    public const string PATH2 = @""; // ��΃p�XPATH2��ݒ�.

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ClassLibrary.dll�̃��[�h.
        try
        {

            // asm1�̃��[�h.
            Assembly asm1 = Assembly.LoadFile(PATH1);   // Assembly.LoadFile�Ő�΃p�XPATH1�����[�h.
            Console.WriteLine("asm1 = " + asm1);  // asm1���o��.

            // asm2�̃��[�h.
            Assembly asm2 = Assembly.LoadFile(PATH2);   // Assembly.LoadFile�Ő�΃p�XPATH2�����[�h.
            Console.WriteLine("asm2 = " + asm2);  // asm2���o��.
            
            // ��r.
            if (asm1.CodeBase == asm2.CodeBase) // �A�Z���u���̏ꏊ���r.
            {
                // �ꏊ�������ꍇ.
                Console.WriteLine("asm1.CodeBase == asm2.CodeBase");    // "asm1.CodeBase == asm2.CodeBase"���o��.
            }
            else
            {
                // �ꏊ���Ⴄ�ꍇ.
                Console.WriteLine("asm1.CodeBase != asm2.CodeBase");    // "asm1.CodeBase != asm2.CodeBase"���o��.
            }

        }
        catch (Exception ex)    // ��O����
        {

            // ��O�o��
            Console.WriteLine(ex.ToString());   // ex.ToString���o��.

        }

    }

}