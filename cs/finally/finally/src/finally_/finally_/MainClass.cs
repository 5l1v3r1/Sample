// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.IO;    // �t�@�C�����o�͂ƃf�[�^�X�g���[��(System.IO���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
        // �ϐ��̏�����.
        StreamReader sr1 = null;    // StreamReader�I�u�W�F�N�gsr1��null�ɏ�����.
        StreamReader sr2 = null;    // StreamReader�I�u�W�F�N�gsr2��null�ɏ�����.
        string text1 = "";          // �e�L�X�g�t�@�C���̓��estring�^text1��""�ɏ�����.
        string text2 = "";          // �e�L�X�g�t�@�C���̓��estring�^text2��""�ɏ�����.

        // �e�L�X�g�t�@�C��"test1.txt"��"test2.txt"�̓��e��A�����ēǂݍ���.
        try
        {
            // try�u���b�N
            // test1.txt��ǂݍ���.
            sr1 = new StreamReader("test1.txt");    // �R���X�g���N�^��"test1.txt"��n����, StreamReader�I�u�W�F�N�g���쐬��, sr1�Ɋi�[.
            text1 = sr1.ReadToEnd();    // sr1.ReadToEnd�Ńe�L�X�g���擾��, text1�Ɋi�[.
            Console.WriteLine("text1 = " + text1);  // text1�̓��e���o��.
            // test2.txt��ǂݍ���.
            sr2 = new StreamReader("test2.txt");    // �R���X�g���N�^��"test2.txt"��n����, StreamReader�I�u�W�F�N�g���쐬��, sr2�Ɋi�[.
            text2 = sr2.ReadToEnd();    // sr2.ReadToEnd�Ńe�L�X�g���擾��, text2�Ɋi�[.
            Console.WriteLine("text2 = " + text2);  // text2�̓��e���o��.
        }
        catch (Exception ex)
        {
            // catch�u���b�N
            // �G���[���b�Z�[�W�̏o��.
            Console.WriteLine("Error: " + ex.Message);  // "Error: "�̌�A��O���b�Z�[�Wex.Message���o��.
        }
        finally
        {
            // finally�u���b�N(�����͐������Ă����s���Ă��K���ʂ�.)
            Console.WriteLine("finally");   // "finally"���o��.
            if (sr2 != null)    // sr2��null�łȂ����.
            {
                // �t�@�C�������.
                sr2.Close();    // sr2.Close�ŕ���.
                sr2 = null; // sr2��null���Z�b�g.
                Console.WriteLine("sr2 closed!");   // "sr2 closed!"���o��.
            }
            if (sr1 != null)    // sr1��null�łȂ����.
            {
                // �t�@�C�������.
                sr1.Close();    // sr1.Close�ŕ���.
                sr1 = null; // sr1��null���Z�b�g.
                Console.WriteLine("sr1 closed!");   // "sr1 closed!"���o��.
            }
        }
    }
}