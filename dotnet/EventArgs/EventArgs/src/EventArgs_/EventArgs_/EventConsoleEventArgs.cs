// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �C�x���g�R���\�[�������N���X
public class EventConsoleEventArgs : EventArgs  // EventConsoleEventArgs�N���X�̒�`
{

    // �����o�̒�`
    private bool result = false;    // �����ϐ�result��false�ŏ�����.
    public bool Result  // true�Ȃ烋�[�v�𔲂���v���p�e�BResult.
    {
        get
        {
            return result;
        }
        set
        {
            result = value;
        }
    }
    private string line = "";   // �����ϐ�line��""�ŏ�����.
    public string Line    // ���͍s����������v���p�e�BLine.
    {
        get
        {
            return line;
        }
        set
        {
            line = value;
        }
    }
}