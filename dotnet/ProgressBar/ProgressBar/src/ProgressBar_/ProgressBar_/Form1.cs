using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ProgressBar_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �v���O���X�o�[��1�X�e�b�v�i�߂�.
            progressBar1.PerformStep(); //  progressBar1.PerformStep��1�X�e�b�v�i�߂�.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // �v���O���X�o�[�̏�����.
            progressBar1.Minimum = 0;   // �ŏ��l��0�Ƃ���.
            progressBar1.Maximum = 100; // �ő�l��100�Ƃ���.
            progressBar1.Step = 10;     // ������10�Ƃ���.
            progressBar1.Value = 0;     // ���ݒl��0�Ƃ���.
        }
    }
}