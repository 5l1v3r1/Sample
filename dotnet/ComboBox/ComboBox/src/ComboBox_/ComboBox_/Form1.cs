using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ComboBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �e�L�X�g�{�b�N�X�����ɓ��͂��ꂽ�A�C�e�������X�g�{�b�N�X�����ɂȂ�������ǉ�.
            if (!comboBox1.Items.Contains(comboBox1.Text))  // comboBox1.Text��comboBox1.Items.Contains�ł݂���Ȃ�.
            {
                comboBox1.Items.Add(comboBox1.Text);    // comboBox1.Items.Add�Œǉ�.
                MessageBox.Show(comboBox1.Text);    // comboBox1.Text��\��.
            }
            else    // �݂�����.
            {
                MessageBox.Show((string)comboBox1.SelectedItem);    // �I�����ꂽ�A�C�e��comboBox1.SelectedItem��\��.
            }
        }
    }
}