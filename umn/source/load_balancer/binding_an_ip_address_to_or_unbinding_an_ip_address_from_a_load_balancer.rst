Binding an IP Address to or Unbinding an IP Address from a Load Balancer
========================================================================

Scenarios
---------

You can bind an IP address to a load balancer or unbind an IP address from a load balancer based on service requirements. If you bind an EIP to a load balancer, it can route requests over the Internet. If the EIP is not needed any longer, you can unbind it from the load balancer.

You can only bind EIPs to or unbind EIPs from shared load balancers.

Binding an EIP
--------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click **More** > **Bind EIP** in the **Operation** column.
#. In the **Bind EIP** dialog box, select the EIP to be bound and click **OK**.

Alternatively, go to the basic information page of the load balancer and click **Bind** next to **EIP**.

Unbinding an EIP
----------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click **More** > **Unbind EIP** in the **Operation** column.
#. Click **Yes**.

Alternatively, go to the basic information page of the load balancer and click **Unbind** next to **EIP**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png

.. |image3| image:: /images/en-us_image_0241356603.png

.. |image4| image:: /images/en-us_image_0000001120894978.png

