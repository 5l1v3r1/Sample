// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)

// �e�X�g�R���N�V�����N���X
class TestCollection : IEnumerable  // TestCollection�N���X�̒�`(IEnumerable�C���^�[�t�F�C�X������.)
{

    // IEnumerator��Ԃ����\�b�hGetEnumerator.
    public IEnumerator GetEnumerator()
    {
        
        // �z��̐���.
        int[] array = new int[5];   // �v�f��5��int�^�z��array�𐶐�.
        for (int i = 0; i < 5; i++) // i��0����4�܂ŌJ��Ԃ�.
        {
            array[i] = i;   // array[i]��i����.
        }
        return array.GetEnumerator();   // array.GetEnumerator��array��Enumerator��Ԃ�.

    }

}