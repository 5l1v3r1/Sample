using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CheckBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �`�F�b�N�{�b�N�X���`�F�b�N����Ă��邩�`�F�b�N����.
            if (checkBox1.Checked)  // checkBox1.Checked��True�Ȃ�`�F�b�N����Ă���.
            {
                MessageBox.Show("checkBox1 Checked!");  // "checkBox1 Checked!"��\��.
            }
            else
            {
                MessageBox.Show("checkBox1 Unchecked!");    // "checkBox1 Unchecked!"��\��.
            }
        }
    }
}