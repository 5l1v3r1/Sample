// Class1�̒�`(B)
partial class Class1
{
    public Class1()
    {
        // ������.
        this.x = 0; // �����o��x��0�ɏ�����.
        this.y = 0; // �����o��y��0�ɏ�����.
        this.result = 0;    // �����o��result��0�ɏ�����.
    }
    public void Add(int x, int y)   // ���Z���\�b�hAdd.
    {
        // ���Z.
        this.x = x; // x�������o�ɃZ�b�g.
        this.y = y; // y�������o�ɃZ�b�g.
        this.result = this.x + this.y;  // this.x��this.y�̉��Z���ʂ�this.result�Ɋi�[.
    }
    public int GetResult()  // ���ʎ擾���\�b�hGetResult.
    {
        // ����.
        return result;  // �����oresult��Ԃ�.
    }
}
