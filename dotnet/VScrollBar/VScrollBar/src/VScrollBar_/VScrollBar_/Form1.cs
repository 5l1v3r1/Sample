using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace VScrollBar_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            // ���������X�N���[��������������, ���x���Ɍ��݂̐��������X�N���[���o�[�̒l���Z�b�g����.
            label1.Text = String.Format("{0:d}", vScrollBar1.Value);    // vScrollBar1.Value��int�Ȃ̂�, String.Format�ŕ�����ɕϊ���, label1.Text�ɃZ�b�g.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // ���������X�N���[���o�[�̍ŏ��l, �ő�l, �y�[�W�T�C�Y(�傫���ړ��������̑���), �����l��ݒ�.
            vScrollBar1.Minimum = 0;        // �ŏ��l��0�Ƃ���.
            vScrollBar1.Maximum = 100;      // �ő�l��100�Ƃ���.
            vScrollBar1.LargeChange = 1;    // �y�[�W�T�C�Y��1�Ƃ���.
            vScrollBar1.Value = 0;          // ���ݒn��0�Ƃ���.
            // ���x���̃e�L�X�g��������.
            label1.Text = String.Format("{0:d}", vScrollBar1.Value);    // vScrollBar1.Value��int�Ȃ̂�, String.Format�ŕ�����ɕϊ���, label1.Text�ɃZ�b�g.
        }
    }
}