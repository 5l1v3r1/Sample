// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �f���Q�[�g�̐錾
public delegate void EventDelegate(string inputString);    // ������string�Ŗ߂�l��void��delegate��錾.

// ���̓`�F�b�N�N���X
public class InputCheckClass // InputCheck�N���X�̒�`
{

    // �����o�t�B�[���h�̒�`
    private string target;  // �C�x���g���������ƂȂ镶����target.
    public event EventDelegate callback;    // EventDelegate�^��event�p�f���Q�[�g�ϐ�callback.
    
    // �����o���\�b�h�̒�`
    // �R���X�g���N�^
    public InputCheckClass(string target)
    {

        // �����������o�ɃZ�b�g.
        this.target = target;   // this.target��target���i�[.

    }

    // �����o���\�b�h
    public void InputCheckLoop()    // ���̓`�F�b�N���[�v���\�b�hInputCheckLoop
    {

        // ���͕�������`�F�b�N.
        do
        {
            string str = Console.ReadLine();    // Console.ReadLine�œǂݍ��񂾕������str�Ɋi�[.
            if (str == target)  // str��target�������Ȃ�.
            {
                callback(str);  // callback�����s.
                break; // ���̃��[�v�𔲂���.
            }
        }
        while (true);   // ���true.

    }

}