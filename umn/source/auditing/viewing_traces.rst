Viewing Traces
==============

Scenarios
---------

CTS records the operations performed on ELB and allows you to view the operation records of the last seven days on the CTS console. To query these records, perform the following operations.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Under **Management & Deployment**, click **Cloud Trace Service**.

#. In the navigation pane on the left, choose **Trace List**.

#. Specify the filters used for querying traces. The following filters are available:**Figure 1** Filters
   |image2|

   -  **Trace Type**, **Trace Source**, **Resource Type**, and **Search By**

      Select a filter from the drop-down list.

      If you select **Trace name** for **Search By**, you need to select a specific trace name.

      If you select **Resource ID** for **Search By**, select or enter a specific resource ID.

      If you select **Resource name** for **Search By**, select or enter a specific resource name.

   -  **Operator**: Select a specific operator (at the user level rather than the tenant level).

   -  **Trace Status**: Available options include **All trace statuses**, **Normal**, **Warning**, and **Incident**. You can only select one of them.

   -  Time range: You can query traces generated at any time range of the last seven days.

#. Click |image3| on the left of the required trace to expand its details.\ **Figure 2** Expanding trace details
   |image4|

#. Click **View Trace** in the **Operation** column to view trace details.\ **Figure 3** View Trace
   |image5|

   For details about key fields in the trace, see the Cloud Trace Service User Guide.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0129028346.png

.. |image3| image:: /images/en-us_image_0114944782.jpg

.. |image4| image:: /images/en-us_image_0153115564.png

.. |image5| image:: /images/en-us_image_0153115565.png

