// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)
using System.Collections.Generic;   // �W�F�l���b�N�R���N�V�����N���X(System.Collections.Generic���O���)

// �e�X�g�R���N�V�����N���X
class TestCollection<T> : ICollection<T>  // TestCollection<T>�N���X�̒�`(ICollection<T>�C���^�[�t�F�C�X������.)
{

    // �����o�t�B�[���h�̒�`
    private T[] collection;   // T�^�z��collection.
    private int size;   // �T�C�Ysize.

    // �R���X�g���N�^
    public TestCollection(int size)
    {
        this.size = size;
        collection = new T[this.size];
    }

    // �C���f�N�T�̒�`
    public T this[int indexer]
    {

        // indexer�Ԗڂ�collection�v�f�ɃA�N�Z�X.
        get
        {
            return collection[indexer];
        }
        set
        {
            collection[indexer] = value;
        }

    }

    // �ǉ�
    public void Add(T item)
    {
        T[] newCollection = new T[size + 1];   // 1�傫���z����쐬.
        collection.CopyTo(newCollection, 0);    // newCollection�ɃR�s�[.
        newCollection[size] = item;    // �Ō�̗v�f��item���w��.
        collection = newCollection; // collection��newCollection���w�����̂Ƃ���.
        size = newCollection.Length;    // size���X�V.
    }

    // �N���A
    public void Clear()
    {

    }

    // �܂܂�Ă��邩.
    public bool Contains(T item)
    {
        return false;   // �Ƃ肠����false��Ԃ�.
    }

    // �R�s�[
    public void CopyTo(T[] array, int arrayIndex)
    {

    }

    // �폜
    public bool Remove(T item)
    {
        return false;   // �Ƃ肠����false��Ԃ�.
    }

    // �v�f��
    public int Count    // count��Ԃ�.
    {
        get
        {
            return size;
        }
    }

    // �ǂݍ��ݐ�p��.
    public bool IsReadOnly
    {
        get
        {
            return false;  // �Ƃ肠����false��Ԃ�.
        }
    }

    // IEnumerator<T>��Ԃ����\�b�hGetEnumerator.
    public IEnumerator<T> GetEnumerator()
    {
        // T[]��collection��GetEnumerator��IEnumerator�Ȃ̂�, ���̂܂ܕԂ��Ȃ��̂�yield�ɂ�����Ԃ���.
        foreach (T v in collection)
        {
            yield return v;
        }
    }

    // ��W�F�l���b�N���錾���Ȃ��Ƃ����Ȃ�.
    IEnumerator IEnumerable.GetEnumerator()
    {
        return this.GetEnumerator();    // IEnumerator<T>���̕���Ԃ�.
    }

}