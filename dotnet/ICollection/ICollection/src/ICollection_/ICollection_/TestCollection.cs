// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)

// �e�X�g�R���N�V�����N���X
class TestCollection : ICollection  // TestCollection�N���X�̒�`(ICollection�C���^�[�t�F�C�X������.)
{

    // �t�B�[���h
    private int[] ary;

    // �v���p�e�B
    private int count;  // �v�f��count.
    public int Count    // count��Ԃ�.
    {
        get
        {
            return count;
        }
    }
    private object syncRoot;
    public object SyncRoot
    {
        get
        {
            return syncRoot;
        }
    }
    private bool isSynchronized;
    public bool IsSynchronized
    {
        get
        {
            return isSynchronized;
        }
    }

    // �R���X�g���N�^TestCollection
    public TestCollection(int count)
    {
        syncRoot = null;    // null�ł���.
        isSynchronized = false; // false�ł���.
        this.count = count;
        ary = new int[count]; // count���̔z��𐶐�.
        for (int i = 0; i < count; i++)
        {
            ary[i] = i; // i�Ԗڂ�i.
        } 
    }

    // ���\�b�hCopyTo
    public void CopyTo(Array array, int index)
    {
        // ����͎������Ȃ�.
    }

    // ���\�b�hGetEnumerator
    // IEnumerator��Ԃ����\�b�hGetEnumerator.
    public IEnumerator GetEnumerator()
    {
        return ary.GetEnumerator();   // ary.GetEnumerator��ary��Enumerator��Ԃ�.
    }

}