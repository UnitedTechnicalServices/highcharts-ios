/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIEvents.h"
#import "HIMarker.h"
#import "HITargetOptions.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
The Data module provides a simplified interface for adding data to a chart from sources like CVS, HTML tables or grid views. See also the [tutorial article on the Data module](http://www.highcharts.com/docs/working- with-data/data-module). It requires the `modules/data.js` file to be loaded. Please note that the default way of adding data in Highcharts, without the need of a module, is through the `series.data` option.

**Try it**

* [HTML table](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/)
* [CSV](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/csv/)
*/
@interface HIData: HIChartsJSONSerializable

/**
A callback function to parse string representations of dates into JavaScript timestamps. Should return an integer timestamp on success.
*/
@property(nonatomic, readwrite) HIFunction *parseDate;
/**
Whether to use the first row in the data set as series names.

**Defaults to** `true`.

**Try it**

* [Don't get series names from the CSV](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *firstRowAsNames;
/**
An array containing object with Point property names along with what column id the property should be taken from.

**Try it**

* [Label from data set](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/seriesmapping-label/)
*/
@property(nonatomic, readwrite) NSArray *seriesMapping;
/**
The same as the columns input option, but defining rows intead of columns.

**Try it**

* [Data in rows](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/rows/)
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *rows;
/**
The callback that is evaluated when the data is finished loading, optionally from an external source, and parsed. The first argument passed is a finished chart options object, containing the series. These options can be extended with additional options and passed directly to the chart constructor.

**Try it**

* [Modify data on complete](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/complete/)
*/
@property(nonatomic, readwrite) HIFunction *complete;
/**
Item or cell delimiter for parsing CSV. Defaults to the tab character `\t` if a tab character is found in the CSV string, if not it defaults to `,`. If this is set to false or undefined, the parser will attempt to deduce the delimiter automatically.

**Try it**

* [Delimiters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/)
*/
@property(nonatomic, readwrite) NSString *itemDelimiter;
/**
Which of the predefined date formats in Date.prototype.dateFormats to use to parse date values. Defaults to a best guess based on what format gives valid and ordered dates. Valid options include: *  `YYYY/mm/dd` *  `dd/mm/YYYY` *  `mm/dd/YYYY` *  `dd/mm/YY` *  `mm/dd/YY`

**Accepted values:** `[undefined, "YYYY/mm/dd", "dd/mm/YYYY", "mm/dd/YYYY",
            "dd/mm/YYYY", "dd/mm/YY", "mm/dd/YY"]`.

**Try it**

* [Best guess date format](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/dateformat-auto/)
*/
@property(nonatomic, readwrite) NSString *dateFormat;
/**
The Google Spreadsheet worksheet to use in combination with `googleSpreadsheetKey`. The available id's from your sheet can be read from `https://spreadsheets.google.com/feeds/worksheets/{key}/public/basic`.

**Try it**

* [Load a Google Spreadsheet](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/)
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetWorksheet;
/**
The key for a Google Spreadsheet to load. See [general information on GS](https://developers.google.com/gdata/samples/spreadsheet_sample).

**Try it**

* [Load a Google Spreadsheet](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/)
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetKey;
/**
Switch rows and columns of the input data, so that `this.columns` effectively becomes the rows of the data set, and the rows are interpreted as series.

**Defaults to** `false`.

**Try it**

* [Switch rows and columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/switchrowsandcolumns/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *switchRowsAndColumns;
/**
In tabular input data, the first row (indexed by 0) to use.

**Defaults to** `0`.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *startRow;
/**
In tabular input data, the first column (indexed by 0) to use.

**Defaults to** `0`.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *startColumn;
/**
In tabular input data, the last column (indexed by 0) to use. Defaults to the last column containing data.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *endColumn;
/**
A HTML table or the id of such to be parsed as input data. Related options are `startRow`, `endRow`, `startColumn` and `endColumn` to delimit what part of the table is used.

**Try it**

* [Parsed table](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/)
*/
@property(nonatomic, readwrite) id table;
/**
The decimal point used for parsing numbers in the CSV. If both this and data.delimiter is set to false, the parser will attempt to deduce the decimal point automatically.

**Defaults to** `.`.

**Try it**

* [Comma as decimal point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/)
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
Line delimiter for parsing CSV.

**Defaults to** `\n`.

**Try it**

* [Delimiters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/)
*/
@property(nonatomic, readwrite) NSString *lineDelimiter;
/**
A comma delimited string to be parsed. Related options are `startRow`, `endRow`, `startColumn` and `endColumn` to delimit what part of the table is used. The `lineDelimiter` and `itemDelimiter` options define the CSV delimiter formats. The built-in CSV parser doesn't support all flavours of CSV, so in some cases it may be necessary to use an external CSV parser. See [this example](http://jsfiddle.net/highcharts/u59176h4/) of parsing CSV through the MIT licensed [Papa Parse](http://papaparse.com/) library.

**Try it**

* [Data from CSV](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/csv/)
*/
@property(nonatomic, readwrite) NSString *csv;
/**
A callback function to access the parsed columns, the two-dimentional input data array directly, before they are interpreted into series data and categories. Return `false` to stop completion, or call `this.complete()` to continue async.

**Try it**

* [Modify data after parse](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/parsed/)
*/
@property(nonatomic, readwrite) HIFunction *parsed;
/**
A two-dimensional array representing the input data on tabular form. This input can be used when the data is already parsed, for example from a grid view component. Each cell can be a string or number. If not switchRowsAndColumns is set, the columns are interpreted as series.

**Try it**

* [Columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/columns/)
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *columns;
/**
In tabular input data, the last row (indexed by 0) to use. Defaults to the last row containing data.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *endRow;
/**
The `high` value for each data point, signifying the highest value in the sample set. The top whisker is drawn here.
*/
@property(nonatomic, readwrite) NSNumber *high;
/**
The lower quartile for each data point. This is the bottom of the box.
*/
@property(nonatomic, readwrite) NSNumber *q1;
/**
The higher quartile for each data point. This is the top of the box.
*/
@property(nonatomic, readwrite) NSNumber *q3;
/**
The median for each data point. This is drawn as a line through the middle area of the box.
*/
@property(nonatomic, readwrite) NSNumber *median;
/**
The `low` value for each data point, signifying the lowest value in the sample set. The bottom whisker is drawn here.
*/
@property(nonatomic, readwrite) NSNumber *low;
/**
The rank for this point's data label in case of collision. If two data labels are about to overlap, only the one with the highest `labelrank` will be drawn.
*/
@property(nonatomic, readwrite) NSNumber *labelrank;
/**
A description of the point to add to the screen reader information about the point. Requires the Accessibility module.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *definition;
/**
The name of the point as shown in the legend, tooltip, dataLabel etc.

**Try it**

* [Point names](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/)
*/
@property(nonatomic, readwrite) NSString *name;
/**
Individual color for the point. By default the color is pulled from the global `colors` array. In styled mode, the `color` option doesn't take effect. Instead, use `colorIndex`.

**Defaults to** `undefined`.

**Try it**

* [Mark the highest point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/color/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Whether the data point is selected initially.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
Individual data label for each point. The options are the same as the ones for `plotOptions.series.dataLabels`

**Try it**

* [Show a label for the last value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/datalabels/)
*/
@property(nonatomic, readwrite) id dataLabels;
/**
An additional, individual class name for the data point's graphic representation.
*/
@property(nonatomic, readwrite) NSString *className;
/**
Individual point events
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
The y value of the point.

**Defaults to** `null`.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x value of the point. For datetime axes, the X value is the timestamp in milliseconds since 1970.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
The `id` of a series in the `drilldown.series` array to use for a drilldown for this point.

**Try it**

* [Basic drilldown](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/basic/)
*/
@property(nonatomic, readwrite) NSString *drilldown;
/**
An id for the point. This can be used after render time to get a pointer to the point object through `chart.get()`.

**Defaults to** `null`.

**Try it**

* [Remove an id'd point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/id/)
*/
@property(nonatomic, readwrite) NSString *id;
/**
A specific color index to use for the point, so its graphic representations are given the class name `highcharts-color-{n}`. In styled mode this will change the color of the graphic. In non-styled mode, the color by is set by the `fill` attribute, so the change in class name won't have a visual effect by default.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
The sequential index of the data point in the legend.
*/
@property(nonatomic, readwrite) NSNumber *legendIndex;
@property(nonatomic, readwrite) HIMarker *marker;
/**
The length of the vector. The rendered length will relate to the `vectorLength` setting.
*/
@property(nonatomic, readwrite) NSNumber *length;
/**
The vector direction in degrees, where 0 is north (pointing towards south).
*/
@property(nonatomic, readwrite) NSNumber *direction;
/**
The target value of a point.
*/
@property(nonatomic, readwrite) NSNumber *target;
/**
Individual target options for each point.
*/
@property(nonatomic, readwrite) HITargetOptions *targetOptions;
/**
The color of the border surrounding the column or bar. In styled mode, the border stroke can be set with the `.highcharts-point` rule.

**Defaults to** `undefined`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The width of the border surrounding the column or bar. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Defaults to** `undefined`.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The value of the point, resulting in a color controled by options as set in the `colorAxis` configuration.
*/
@property(nonatomic, readwrite) NSNumber *value;
/**
Point padding for a single point.

**Try it**

* [Point padding on tiles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/tilemap-pointpadding)
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
When this property is true, the points acts as a summary column for the values added or substracted since the last intermediate sum, or since the start of the series. The `y` value is ignored.

**Defaults to** `false`.

**Try it**

* [Waterfall](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *isIntermediateSum;
/**
When this property is true, the point display the total sum across the entire series. The `y` value is ignored.

**Defaults to** `false`.

**Try it**

* [Waterfall](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *isSum;
/**
Whether to display a slice offset from the center.

**Try it**

* [One sliced point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/sliced/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *sliced;
/**
The inner radius of an individual point in a solid gauge. Can be given as a number (pixels) or percentage string.

**Try it**

* [Individual radius and innerRadius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/solidgauge-radius/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ innerRadius;
/**
The outer radius of an individual point in a solid gauge. Can be given as a number (pixels) or percentage string.

**Try it**

* [Individual radius and innerRadius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/solidgauge-radius/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ radius;
/**
The node that the link runs to.
*/
@property(nonatomic, readwrite) NSString *to;
/**
Whether the link goes out of the system.

**Defaults to** `false`.

**Try it**

* [Sankey chart with outgoing links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-outgoing)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *outgoing;
/**
The node that the link runs from.
*/
@property(nonatomic, readwrite) NSString *from;
/**
The weight of the link.
*/
@property(nonatomic, readwrite) NSNumber *weight;
/**
The size value for each bubble. The bubbles' diameters are computed based on the `z`, and controlled by series options like `minSize`, `maxSize`, `sizeBy`, `zMin` and `zMax`.
*/
@property(nonatomic, readwrite) NSNumber *z;
/**
Serves a purpose only if a `colorAxis` object is defined in the chart options. This value will decide which color the point gets from the scale of the colorAxis.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSNumber *colorValue;
/**
Only for treemap. Use this option to build a tree structure. The value should be the id of the point which is the parent. If no points has a matching id, or this option is undefined, then the parent will be set to the root.

**Defaults to** `undefined`.

**Try it**

* [Point parent](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/parent/)
* [Example where parent id is not matching](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-with-levels/)
*/
@property(nonatomic, readwrite) NSString *parent;

-(NSDictionary *)getParams;

@end
