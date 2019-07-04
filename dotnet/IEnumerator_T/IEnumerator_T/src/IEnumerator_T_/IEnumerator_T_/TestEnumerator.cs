// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)
using System.Collections.Generic;   // �W�F�l���b�N�R���N�V�����N���X(System.Collections.Generic���O���)

// �e�X�g�C�i�~�����[�^�N���X
class TestEnumerator<T> : IEnumerator<T>  // TestEnumerator<T>�N���X�̒�`(IEnumerator<T>�C���^�[�t�F�C�X������.)
{

    // �����o�t�B�[���h�̒�`
    private T[] container;    // �R���X�g���N�^�œn���ꂽT�^�z��̎Q�Ƃ�����T�^�z��container.
    private int length;         // container�̑傫��������int�^�ϐ�length.
    private int index;          // ���݈ʒu + 1������int�^�ϐ�index.(1����n�܂��Ă��܂��̂�.)

    // IEnumerator<T>.Current�v���p�e�B
    public T Current
    {
        get
        {
            // �Ă΂ꂽ���Ƃ��o��.
            Console.WriteLine("index = " + (index - 1) + ", Current = " + container[index - 1]);   // index��Current���o��.
            return container[index - 1];    // container[index - 1]��Ԃ�.
            
        }
    }

    // IEnumerator.Current�v���p�e�B
    object IEnumerator.Current
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

    // IEnumerator.MoveNext���\�b�h
    bool IEnumerator.MoveNext()
    { // ���ꂪ��ԍŏ��ɌĂ΂�Ă��܂��̂�, index��1����n�܂�悤�ɂȂ�, �������O������݂��0����4�Ŏw�肷��悤�ɒ���.

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

    // IEnumerator.Reset���\�b�h
    void IEnumerator.Reset()
    {

        // �Ă΂ꂽ���Ƃ��o��.
        Console.WriteLine("Reset");   // "Reset"���o��.

        // �ʒu���ŏ��̗v�f�ɖ߂�.
        index = 0;  // index��0�ɃZ�b�g.

    }

    // ���\�[�X������\�b�hDispose(IDispose�̃����o�̃I�[�o�[���C�h.)
    void IDisposable.Dispose()
    {
        // �I������.
        container = null;
        length = 0;
        index = 0;
    }

}