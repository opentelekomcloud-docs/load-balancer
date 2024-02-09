:original_name: elb_ug_ip_0002.html

.. _elb_ug_ip_0002:

Managing IP Addresses in an IP Address Group
============================================

After an IP address group is created, you can manage the IP addresses in an IP address group as required:

-  :ref:`Adding IP Addresses <elb_ug_ip_0002__section1870011618404>`
-  :ref:`Changing IP Addresses <elb_ug_ip_0002__section242243784118>`
-  :ref:`Deleting an IP Address <elb_ug_ip_0002__section14993123018571>`

Constraints
-----------

The IP addresses can be in the following formats:

-  Each IP address or CIDR block must be on a separate line and end with a carriage return.
-  Each IP address or CIDR block can include a description with a vertical bar (|) separated, for example, 192.168.10.10 \| ECS01. The description is 0 to 255 characters long and cannot contain angle brackets (<>).
-  You can add a maximum of 300 IP addresses and CIDR blocks in each IP address group.

.. _elb_ug_ip_0002__section1870011618404:

Adding IP Addresses
-------------------

After an IP address group is created, you can add IP addresses to an IP address group.

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balance** > **IP Address Groups**.
#. On the **IP Address Groups** page, click the name of the target address group.
#. In the lower part of the displayed page, choose **IP Addresses** tab and click **Add IP Addresses**.
#. On the **Add IP Addresses** page, add IP addresses.
#. Click **OK**.

.. _elb_ug_ip_0002__section242243784118:

Changing IP Addresses
---------------------

You can perform the following steps to change all IP addresses in an IP address group:

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balance** > **IP Address Groups**.
#. On the **IP Address Groups** page, you can:

   a. Modify the basic information and change IP addresses of an IP address group:

      #. Locate the target address group, click **Modify** in the **Operation** column.
      #. You can modify the name and description of an IP address group, and change all its IP addresses.
      #. Click **OK**.

   b. Only change IP addresses:

      #. Click the name of the target IP address group.
      #. In the lower part of the displayed page, choose **IP Addresses** tab and click **Change IP Address**.
      #. Change IP addresses as you needed.
      #. Click **OK**.

.. _elb_ug_ip_0002__section14993123018571:

Deleting an IP Address
----------------------

If you want to delete IP addresses in batches from an IP address group, see :ref:`Changing IP Addresses <elb_ug_ip_0002__section242243784118>`.

To delete an IP address from an IP address group, perform the following operations:

#. Log in to the management console.

#. In the upper left corner of the page, click |image5| and select the desired region and project.

#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the navigation pane on the left, choose **Elastic Load Balance** > **IP Address Groups**.

#. On the **IP Address Groups** page, click the name of the target address group.

#. In the IP address list, locate the IP address you want to delete and click **Delete** in the **Operation** column.

   A confirmation dialog box is displayed.

#. Confirm the information and click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
.. |image5| image:: /_static/images/en-us_image_0000001747739624.png
.. |image6| image:: /_static/images/en-us_image_0000001794660485.png
