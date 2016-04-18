using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MessageBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Yes/No(�͂�/������)���b�Z�[�W�{�b�N�X��\������.
            DialogResult dr = MessageBox.Show("Yes or No?", "MessageBox_", MessageBoxButtons.YesNo, MessageBoxIcon.Question);   // MessageBox.Show��, �e�L�X�g��"Yes or No?"��, �L���v�V������"MessageBox_"��, �A�C�R����?��Yes/No��MessageBox��\��.(DialogResult�^��dr�ɂǂ���������������ʂ��i�[�����.)
            if (dr == DialogResult.Yes) // Yes�̏ꍇ.
            {
                MessageBox.Show("Yes"); // "Yes"�ƕ\��.
            }
            else    // No�̏ꍇ.
            {
                MessageBox.Show("No");  // "No"�ƕ\��.
            }
        }
    }
}