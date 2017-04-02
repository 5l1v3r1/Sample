// ���O��Ԃ̓o�^
using System;               // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)

// �e�X�g�C�i�~�����[�^�N���X
class TestEnumerator : IEnumerator  // TestEnumerator�N���X�̒�`(IEnumerator�C���^�[�t�F�C�X������.)
{

    // �����o�t�B�[���h�̒�`
    private int[] container;    // �R���X�g���N�^�œn���ꂽint�^�z��̎Q�Ƃ�����int�^�z��container.
    private int length;         // container�̑傫��������int�^�ϐ�length.
    private int index;          // ���݈ʒu + 1������int�^�ϐ�index.(1����n�܂��Ă��܂��̂�.)

    // Current�v���p�e�B
    public object Current
    {
        get
        {
            // �͈͓��Ȃ�I�u�W�F�N�g��Ԃ�.
            if (index >= 1 && index <= length)   // index��1�ȏ�length�ȉ��Ȃ�v�f��Ԃ�.
            {
                // �Ă΂ꂽ���Ƃ��o��.
                Console.WriteLine("index = " + (index - 1) + ", Current = " + container[index - 1]);   // index��Current���o��.
                return container[index - 1];    // container[index - 1]��Ԃ�.
            }
            else
            {
                return null;    // null��Ԃ�.
            }
        }
    }

    // �R���X�g���N�^
    public TestEnumerator(int[] con, int len)
    {

        // �����o�Ɋi�[.
        container = con;    // con��container�Ɋi�[.
        length = len;       // len��length�Ɋi�[.
        index = 0;          // index��0�ɃZ�b�g.

    }

    // MoveNext���\�b�h
    public bool MoveNext(){ // ���ꂪ��ԍŏ��ɌĂ΂�Ă��܂��̂�, index��1����n�܂�悤�ɂȂ�, �������O������݂��0����4�Ŏw�肷��悤�ɒ���.

        // 1��ɐi�߂�.
        index++;    // index��1���₷.
        if (index <= length) // index���͈͓��Ȃ�.
        {
            // �Ă΂ꂽ���Ƃ��o��.
            Console.WriteLine("MoveNext, index = " + (index - 1));   // index - 1���o��.
            return true;    // true��Ԃ�.
        }
        else    // index���͈͊O�Ȃ�.
        {
            index--;    // index��1���炷.
            return false;   // false��Ԃ�.
        }

    }

    // Reset���\�b�h
    public void Reset()
    {

        // �Ă΂ꂽ���Ƃ��o��.
        Console.WriteLine("Reset");   // "Reset"���o��.

        // �ʒu���ŏ��̗v�f�ɖ߂�.
        index = 0;  // index��0�ɃZ�b�g.

    }

}