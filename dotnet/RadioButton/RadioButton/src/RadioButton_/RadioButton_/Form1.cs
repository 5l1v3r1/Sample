using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace RadioButton_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �ǂ̃��W�I�{�^�����I������Ă��邩�`�F�b�N����.
            if (radioButton1.Checked)   // radioButton1���I������Ă��鎞.
            {
                MessageBox.Show("radioButton1");    // "radioButton1"��\��.
            }
            else if (radioButton2.Checked)  // radioButton2���I������Ă��鎞.
            {
                MessageBox.Show("radioButton2");    // "radioButton2"��\��.
            }
            else    // radioButton3���I������Ă��鎞.
            {
                MessageBox.Show("radioButton3");    // "radioButton3"��\��.
            }
        }
    }
}