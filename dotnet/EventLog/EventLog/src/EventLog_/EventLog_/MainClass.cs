// ���O��Ԃ̓o�^
using System;               // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Diagnostics;   // �V�X�e���v���Z�X��C�x���g���O�Ƃ̑Θb���邽�߂̃N���X.(System.Diagnostics���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // try�u���b�N
        try
        {

            // �C�x���g���O�ɏ�������.
            EventLog.WriteEntry("EventLog_", "Log Message!");   // EventLog�̃X�^�e�B�b�N���\�b�hWriteEntry��"EventLog_"�Ƃ����\�[�X��"Log Message!"�Ə�������.

        }
        catch (Exception ex)
        {

            // ex�̓��e���o��.
            Console.WriteLine(ex);  // ex�̓��e���o��.

        }

    }

}