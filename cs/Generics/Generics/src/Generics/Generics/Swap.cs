// �X���b�v�N���X
class Swap<T>   // Swap<T>�N���X�̒�`
{

    // �����o�t�B�[���h�̒�`
    private T x;    // T�^�t�B�[���hx.
    public T X     // T�^�l��Ԃ��v���p�e�BX.
    {
        get // �擾��
        {
            return x;   // x��Ԃ�.
        }
        set // �ݒ莞
        {
            x = value;  // �n���ꂽ�l��x�Ɋi�[.
        }
    }
    private T y;    // T�^�t�B�[���hy.
    public T Y     // T�^�l��Ԃ��v���p�e�BY.
    {
        get // �擾��
        {
            return y;   // y��Ԃ�.
        }
        set // �ݒ莞
        {
            y = value;  // �n���ꂽ�l��y�Ɋi�[.
        }
    }

    // �����o���\�b�h�̒�`
    public void DoSwap()    // �X���b�v���s���\�b�hDoSwap
    {

        // �ϐ��̐錾
        T tmp;  // T�^�ꎞ�ϐ�tmp.

        // �X���b�v����.
        tmp = X;    // tmp��X���i�[.
        X = Y;      // X��Y���i�[.
        Y = tmp;    // Y��tmp���i�[.

    }

}